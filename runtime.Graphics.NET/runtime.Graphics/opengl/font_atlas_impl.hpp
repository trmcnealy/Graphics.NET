/*******************************************************
 * Copyright (c) 2015-2019, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

/**
 * @author Pradeep Garigipati (pradeep@arrayfire.com)
 *
 * A font atlas is used to pack several small regions into a single texture.
 *
 * It is an implementation of Skyline Bottom-Left algorithm described
 * in the article by Jukka Jylänki : "A  Thousand Ways to Pack the Bin -
 * A Practical Approach to Two-Dimensional Rectangle Bin Packing",
 * February 27, 2010. Following code also loosely follows C++ sources provided
 * by Jukka Jylänki at: http://clb.demon.fi/files/RectangleBinPack/ for the
 * implementation of the Skyline Bottom-Left algorithm.
 */

#pragma once

#include <Types.hpp>

#include <runtime.Graphics/defines.hpp>

namespace forge
{
    namespace opengl
    {
        class FontAtlas
        {
        private:
            size_type mWidth;
            size_type mHeight;
            size_type mDepth;
            size_type mUsed;
            uint32_t  mId;

            std::vector<unsigned char> mData;
            std::vector<glm::vec3>     nodes;

            /* helper functions */
            int  fit(const size_type pIndex, const size_type pWidth, const size_type pHeight);
            void merge();

        public:
            FontAtlas(const size_type pWidth, const size_type pHeight, const size_type pDepth);
            ~FontAtlas();

            size_type width() const;
            size_type height() const;
            size_type depth() const;

            glm::vec4 getRegion(const size_type pWidth, const size_type pHeight);
            bool      setRegion(const size_type pX, const size_type pY, const size_type pWidth, const size_type pHeight, const unsigned char* pData, const size_type pStride);

            void upload();
            void clear();

            uint32_t atlasTextureId() const;
        };

        struct Glyph
        {
            size_type mWidth;
            size_type mHeight;

            int mBearingX;
            int mBearingY;

            float mAdvanceX;
            float mAdvanceY;

            /* normalized texture coordinate (x) of top-left corner */
            float mS0, mT0;

            /* First normalized texture coordinate (x) of bottom-right corner */
            float mS1, mT1;

            /* render quad vbo offset */
            size_type mOffset;
        };

    } // namespace opengl
} // namespace forge
