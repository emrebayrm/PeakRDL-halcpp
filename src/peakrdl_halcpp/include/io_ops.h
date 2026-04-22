#pragma once
#include <cstdint>
#include <concepts>

template<typename T>
concept IO_Ops = requires(T t, uint32_t address, uint32_t data)
{
    {t.write32(address,data)} -> std::same_as<void>;
    {t.read32(address)} -> std::same_as<uint32_t>;
    {t.get_abs_addr()} -> std::same_as<uintptr_t>;
};