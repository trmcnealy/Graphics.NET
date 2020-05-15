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

#include <runtime.Graphics/opengl/font_atlas_impl.hpp>
#include <runtime.Graphics/opengl/shader_program.hpp>

#include <map>

namespace forge
{
    namespace opengl
    {
        typedef std::vector<Glyph*> GlyphList;

        class font_impl
        {
        private:
            /* VAO map to store a vertex array object
             * for each valid window context */
            std::map<int, unsigned int> mVAOMap;

            /* attributes */
            std::string                mTTFfile;
            bool                       mIsFontLoaded;
            std::unique_ptr<FontAtlas> mAtlas;
            unsigned int               mVBO;
            ShaderProgram              mProgram;
            size_type                  mOrthoW;
            size_type                  mOrthoH;

            std::vector<GlyphList> mGlyphLists;

            /* OpenGL Data */
            glm::mat4    mProjMat;
            unsigned int mPMatIndex;
            unsigned int mMMatIndex;
            unsigned int mTexIndex;
            unsigned int mClrIndex;

            /* load all glyphs and create character atlas */
            void loadAtlasWithGlyphs(const size_type pFontSize);

            /* helper functions to bind and unbind
             * rendering resources */
            void bindResources(int pWindowId);
            void unbindResources() const;

            /* helper to destroy GL objects created for
             * given font face and size if required */
            void destroyGLResources();

        public:
            font_impl();
            ~font_impl();

            void setOthro2D(size_type pWidth, size_type pHeight);
            void loadFont(const char* const pFile);
            void loadSystemFont(const char* const pName);

            void render(int pWindowId, const float pPos[2], const float pColor[4], const char* pText, size_type pFontSize, bool pIsVertical = false);
        };

    } // namespace opengl
} // namespace forge
