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

#include <runtime.Graphics/opengl/backend.hpp>
#include <runtime.Graphics/chart.hpp>
#include <runtime.Graphics/font.hpp>
#include <runtime.Graphics/image.hpp>
#include <runtime.Graphics/opengl/window_impl.hpp>

#include <memory>

namespace forge
{
    namespace common
    {
        class Window
        {
        private:
            std::shared_ptr<detail::window_impl> mWindow;

            Window() {}

        public:
            Window(const int pWidth, const int pHeight, const char* pTitle, const Window* pWindow, const bool invisible = false)
            {
                if(pWindow)
                {
                    mWindow = std::make_shared<detail::window_impl>(pWidth, pHeight, pTitle, pWindow->impl(), invisible);
                }
                else
                {
                    std::shared_ptr<detail::window_impl> other;
                    mWindow = std::make_shared<detail::window_impl>(pWidth, pHeight, pTitle, other, invisible);
                }
            }

            Window(const fg_window pOther) { mWindow = reinterpret_cast<Window*>(pOther)->impl(); }

            __inline const std::shared_ptr<detail::window_impl>& impl() const { return mWindow; }

            __inline void setFont(Font* pFont) { mWindow->setFont(pFont->impl()); }

            __inline void setTitle(const char* pTitle) { mWindow->setTitle(pTitle); }

            __inline void setPos(const int pX, const int pY) { mWindow->setPos(pX, pY); }

            __inline void setSize(const unsigned pWidth, const unsigned pHeight) { mWindow->setSize(pWidth, pHeight); }

            __inline void setColorMap(const forge::ColorMap cmap) { mWindow->setColorMap(cmap); }

            __inline int getID() const { return mWindow->getID(); }

            __inline long long context() const { return mWindow->context(); }

            __inline long long display() const { return mWindow->display(); }

            __inline int width() const { return mWindow->width(); }

            __inline int height() const { return mWindow->height(); }

            __inline void makeCurrent() { mWindow->makeContextCurrent(); }

            __inline void hide() { mWindow->hide(); }

            __inline void show() { mWindow->show(); }

            __inline bool close() { return mWindow->close(); }

            __inline void draw(Image* pImage, const bool pKeepAspectRatio)
            {
                pImage->keepAspectRatio(pKeepAspectRatio);
                mWindow->draw(pImage->impl());
            }

            __inline void draw(const Chart* pChart) { mWindow->draw(pChart->impl()); }

            __inline void swapBuffers() { mWindow->swapBuffers(); }

            template<typename T>
            void draw(const int pRows, const int pCols, const int pIndex, T* pRenderable, const char* pTitle)
            {
                mWindow->draw(pRows, pCols, pIndex, pRenderable->impl(), pTitle);
            }

            void draw(const int pRows, const int pCols, const int pIndex, Image* pRenderable, const char* pTitle, const bool pKeepAspectRatio)
            {
                pRenderable->keepAspectRatio(pKeepAspectRatio);
                mWindow->draw(pRows, pCols, pIndex, pRenderable->impl(), pTitle);
            }

            __inline void saveFrameBuffer(const char* pFullPath) { mWindow->saveFrameBuffer(pFullPath); }
        };

    }
}
