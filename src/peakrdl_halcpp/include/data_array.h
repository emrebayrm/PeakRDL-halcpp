#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>
#include "array_nodes.h"

/**
 * @brief Compile-time array of snapshot data structs, each with its absolute offset baked in.
 *
 * @tparam T       Data struct template — accepts a single uint32_t (absolute offset/base).
 * @tparam BASE    Absolute address of element 0.
 * @tparam STRIDE  Byte distance between consecutive elements.
 * @tparam N       Number of elements.
 *
 * Storage is std::array<T<0>, N>. All T<OFFSET> instantiations have identical memory
 * layout (OFFSET only affects method bodies and constexpr values, not data members),
 * so T<0> is used as the canonical storage type. at<I>() reinterpret_casts to
 * T<BASE + I*STRIDE>& to restore the correct offset-aware type for reads/writes.
 *
 * DataArray is an aggregate — it can be initialized with a brace-enclosed list:
 *   DataArray<Reg_t, 0x10, 4, 2> arr = { {.FIELD=1}, {.FIELD=2} };
 */
template<template<uint32_t> class T, uint32_t BASE, uint32_t STRIDE, size_t N>
struct DataArray {
    std::array<T<0>, N> storage;

    DataArray() = default;

    // Construct from a brace-enclosed list of T<0> values.
    // Each element can use designated initializers since T<0> is a struct:
    //   DataArray<Reg_t, BASE, STRIDE, 2>{ {.FIELD=1}, {.FIELD=2} }
    DataArray(std::initializer_list<T<0>> init) {
        auto it = init.begin();
        for (size_t i = 0; i < N && it != init.end(); ++i, ++it)
            storage[i] = *it;
    }

    template<size_t I>
    T<BASE + I * STRIDE>& at() {
        return reinterpret_cast<T<BASE + I * STRIDE>&>(storage[I]);
    }

    template<size_t I>
    const T<BASE + I * STRIDE>& at() const {
        return reinterpret_cast<const T<BASE + I * STRIDE>&>(storage[I]);
    }

    template<typename IO>
    void read_all(const IO& io_ops) {
        halcpp::loop<size_t, N>([&](auto i) {
            constexpr size_t I = decltype(i)::value;
            if constexpr (requires { at<I>().read_all(io_ops); })
                at<I>().read_all(io_ops);
        });
    }

    template<typename IO>
    void write_all(IO& io_ops) const {
        halcpp::loop<size_t, N>([&](auto i) {
            constexpr size_t I = decltype(i)::value;
            if constexpr (requires { at<I>().write_all(io_ops); })
                at<I>().write_all(io_ops);
        });
    }

    template<size_t I, typename IO>
    void read_at(const IO& io_ops) {
        if constexpr (requires { at<I>().read_all(io_ops); })
            at<I>().read_all(io_ops);
    }

    template<size_t I, typename IO>
    void write_at(IO& io_ops) const {
        if constexpr (requires { at<I>().write_all(io_ops); })
            at<I>().write_all(io_ops);
    }

    std::string to_string(const std::string& indent = "") const {
        std::string s;
        halcpp::loop<size_t, N>([&](auto i) {
            constexpr size_t I = decltype(i)::value;
            s += indent + "[" + std::to_string(I) + "]:\n";
            s += at<I>().to_string(indent + "  ");
        });
        return s;
    }
};
