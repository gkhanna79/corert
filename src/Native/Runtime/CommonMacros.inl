//
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
//

inline UIntNative ALIGN_UP( UIntNative val, UIntNative alignment )
{
    // alignment must be a power of 2 for this implementation to work (need modulo otherwise)
    ASSERT( 0 == (alignment & (alignment - 1)) ); 
    UIntNative result = (val + (alignment - 1)) & ~(alignment - 1);
    ASSERT( result >= val );      // check for overflow

    return result;
}

template <typename T>
inline T* ALIGN_UP(T* val, UIntNative alignment)
{
    return reinterpret_cast<T*>(ALIGN_UP(reinterpret_cast<UIntNative>(val), alignment));
}

inline UIntNative ALIGN_DOWN( UIntNative val, UIntNative alignment )
{
    // alignment must be a power of 2 for this implementation to work (need modulo otherwise)
    ASSERT( 0 == (alignment & (alignment - 1)) );
    UIntNative result = val & ~(alignment - 1);
    return result;
}

template <typename T>
inline T* ALIGN_DOWN(T* val, UIntNative alignment)
{
    return reinterpret_cast<T*>(ALIGN_DOWN(reinterpret_cast<UIntNative>(val), alignment));
}

inline bool IS_ALIGNED(UIntNative val, UIntNative alignment)
{
    ASSERT(0 == (alignment & (alignment - 1)));
    return 0 == (val & (alignment - 1));
}

template <typename T>
inline bool IS_ALIGNED(T* val, UIntNative alignment)
{
    ASSERT(0 == (alignment & (alignment - 1)));
    return IS_ALIGNED(reinterpret_cast<UIntNative>(val), alignment);
}

