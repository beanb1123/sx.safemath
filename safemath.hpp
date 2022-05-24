#pragma once

namespace safemath {

    static uint64_t add( const uint64_t x, const uint64_t y ) {
        const uint64_t z = x + y;
        eosio::check( z >= x, "safemath-add-overflow"); return z;
    }

    static uint64_t sub(const uint64_t x, const uint64_t y) {
        const uint64_t z = x - y;
        eosio::check(z <= x, "safemath-sub-overflow"); return z;
    }

    static uint128_t mul(const uint64_t x, const uint64_t y) {
        const uint128_t z = static_cast<uint128_t>(x) * y;
        eosio::check(y == 0 || z / y == x, "safemath-mul-overflow"); return z;
    }

    static uint64_t div(const uint64_t x, const uint64_t y) {
        eosio::check(y > 0, "safemath-divide-zero");
        return x / y;
    }
}
