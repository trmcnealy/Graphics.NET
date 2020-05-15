/*******************************************************
 * Copyright (c) 2015-2019, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#pragma once

#include <Types.hpp>

namespace forge
{
    namespace opengl
    {
        using ContextHandle = long long;
        using DisplayHandle = long long;

        ContextHandle getCurrentContextHandle();

        DisplayHandle getCurrentDisplayHandle();

    } // namespace opengl
} // namespace forge