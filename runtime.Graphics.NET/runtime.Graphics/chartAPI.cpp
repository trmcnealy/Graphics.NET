/*******************************************************
 * Copyright (c) 2015-2019, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <runtime.Graphics/chart.h>
#include <runtime.Graphics/exception.h>
#include <runtime.Graphics/font.h>
#include <runtime.Graphics/histogram.h>
#include <runtime.Graphics/image.h>
#include <runtime.Graphics/plot.h>
#include <runtime.Graphics/surface.h>
#include <runtime.Graphics/window.h>
#include <runtime.Graphics/chart.hpp>
#include <runtime.Graphics/chart_renderables.hpp>
#include <runtime.Graphics/err_handling.hpp>
#include <runtime.Graphics/font.hpp>
#include <runtime.Graphics/handle.hpp>
#include <runtime.Graphics/image.hpp>
#include <runtime.Graphics/window.hpp>

using namespace forge;
using namespace forge::common;

fg_err fg_create_chart(fg_chart* pChart, const fg_chart_type pChartType)
{
    try
    {
        *pChart = getHandle(new common::Chart(pChartType));
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_retain_chart(fg_chart* pOut, fg_chart pChart)
{
    try
    {
        ARG_ASSERT(1, (pChart != nullptr));

        common::Chart* temp = new common::Chart(pChart);
        *pOut               = getHandle(temp);
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_release_chart(fg_chart pChart)
{
    try
    {
        ARG_ASSERT(0, (pChart != nullptr));

        delete getChart(pChart);
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_set_chart_axes_titles(fg_chart pChart, const char* pX, const char* pY, const char* pZ)
{
    try
    {
        ARG_ASSERT(0, (pChart != nullptr));

        getChart(pChart)->setAxesTitles(pX, pY, pZ);
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_set_chart_axes_limits(fg_chart pChart, const float pXmin, const float pXmax, const float pYmin, const float pYmax, const float pZmin, const float pZmax)
{
    try
    {
        ARG_ASSERT(0, (pChart != nullptr));

        getChart(pChart)->setAxesLimits(pXmin, pXmax, pYmin, pYmax, pZmin, pZmax);
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_set_chart_label_format(fg_chart pChart, const char* pXFormat, const char* pYFormat, const char* pZFormat)
{
    try
    {
        ARG_ASSERT(0, (pChart != nullptr));
        ARG_ASSERT(1, (pXFormat != nullptr));
        ARG_ASSERT(2, (pYFormat != nullptr));
        ARG_ASSERT(3, (pZFormat != nullptr));

        getChart(pChart)->setAxesLabelFormat(pXFormat, pYFormat, pZFormat);
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_get_chart_axes_limits(float* pXmin, float* pXmax, float* pYmin, float* pYmax, float* pZmin, float* pZmax, const fg_chart pChart)
{
    try
    {
        ARG_ASSERT(6, (pChart != nullptr));

        float xmin, xmax, ymin, ymax, zmin, zmax;
        getChart(pChart)->getAxesLimits(&xmin, &xmax, &ymin, &ymax, &zmin, &zmax);

        // Check for NULLs and assign
        if(pXmin)
            *pXmin = xmin;
        if(pXmax)
            *pXmax = xmax;
        if(pYmin)
            *pYmin = ymin;
        if(pYmax)
            *pYmax = ymax;
        if(pZmin)
            *pZmin = zmin;
        if(pZmax)
            *pZmax = zmax;
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_set_chart_legend_position(fg_chart pChart, const float pX, const float pY)
{
    try
    {
        ARG_ASSERT(0, (pChart != nullptr));
        ARG_ASSERT(0, (pX >= 0));
        ARG_ASSERT(0, (pY >= 0));

        getChart(pChart)->setLegendPosition(pX, pY);
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_append_image_to_chart(fg_chart pChart, fg_image pImage)
{
    try
    {
        ARG_ASSERT(0, (pChart != nullptr));
        ARG_ASSERT(1, (pImage != nullptr));

        getChart(pChart)->addRenderable(getImage(pImage)->impl());
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_append_histogram_to_chart(fg_chart pChart, fg_histogram pHistogram)
{
    try
    {
        ARG_ASSERT(0, (pChart != nullptr));
        ARG_ASSERT(1, (pHistogram != nullptr));

        getChart(pChart)->addRenderable(getHistogram(pHistogram)->impl());
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_append_plot_to_chart(fg_chart pChart, fg_plot pPlot)
{
    try
    {
        ARG_ASSERT(0, (pChart != nullptr));
        ARG_ASSERT(1, (pPlot != nullptr));

        getChart(pChart)->addRenderable(getPlot(pPlot)->impl());
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_append_surface_to_chart(fg_chart pChart, fg_surface pSurface)
{
    try
    {
        ARG_ASSERT(0, (pChart != nullptr));
        ARG_ASSERT(1, (pSurface != nullptr));

        getChart(pChart)->addRenderable(getSurface(pSurface)->impl());
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_append_vector_field_to_chart(fg_chart pChart, fg_vector_field pField)
{
    try
    {
        ARG_ASSERT(0, (pChart != nullptr));
        ARG_ASSERT(1, (pField != nullptr));

        getChart(pChart)->addRenderable(getVectorField(pField)->impl());
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_add_image_to_chart(fg_image* pImage, fg_chart pChart, const unsigned pWidth, const unsigned pHeight, const fg_channel_format pFormat, const fg_dtype pType)
{
    try
    {
        ARG_ASSERT(1, (pChart != nullptr));
        ARG_ASSERT(2, (pWidth > 0));
        ARG_ASSERT(3, (pHeight > 0));

        common::Image* img = new common::Image(pWidth, pHeight, pFormat, (forge::dtype)pType);
        getChart(pChart)->addRenderable(img->impl());
        *pImage = getHandle(img);
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_add_histogram_to_chart(fg_histogram* pHistogram, fg_chart pChart, const unsigned pNBins, const fg_dtype pType)
{
    try
    {
        ARG_ASSERT(1, (pChart != nullptr));
        ARG_ASSERT(2, (pNBins > 0));

        common::Chart* chrt = getChart(pChart);

        // Histogram is only allowed in FG_CHART_2D
        ARG_ASSERT(5, chrt->chartType() == FG_CHART_2D);

        common::Histogram* hist = new common::Histogram(pNBins, (forge::dtype)pType);
        chrt->addRenderable(hist->impl());
        *pHistogram = getHandle(hist);
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_add_plot_to_chart(fg_plot* pPlot, fg_chart pChart, const unsigned pNPoints, const fg_dtype pType, const fg_plot_type pPlotType, const fg_marker_type pMarkerType)
{
    try
    {
        ARG_ASSERT(1, (pChart != nullptr));
        ARG_ASSERT(2, (pNPoints > 0));

        common::Chart*   chrt  = getChart(pChart);
        forge::ChartType ctype = chrt->chartType();

        if(ctype == FG_CHART_2D)
        {
            common::Plot* plt = new common::Plot(pNPoints, (forge::dtype)pType, pPlotType, pMarkerType, FG_CHART_2D);
            chrt->addRenderable(plt->impl());
            *pPlot = getHandle(plt);
        }
        else
        {
            common::Plot* plt = new common::Plot(pNPoints, (forge::dtype)pType, pPlotType, pMarkerType, FG_CHART_3D);
            chrt->addRenderable(plt->impl());
            *pPlot = getHandle(plt);
        }
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_add_surface_to_chart(fg_surface*          pSurface,
                               fg_chart             pChart,
                               const unsigned       pXPoints,
                               const unsigned       pYPoints,
                               const fg_dtype       pType,
                               const fg_plot_type   pPlotType,
                               const fg_marker_type pMarkerType)
{
    try
    {
        ARG_ASSERT(1, (pChart != nullptr));
        ARG_ASSERT(2, (pXPoints > 0));
        ARG_ASSERT(3, (pYPoints > 0));

        common::Chart* chrt = getChart(pChart);

        // Surface is only allowed in FG_CHART_3D
        ARG_ASSERT(5, chrt->chartType() == FG_CHART_3D);

        common::Surface* surf = new common::Surface(pXPoints, pYPoints, (forge::dtype)pType, pPlotType, pMarkerType);
        chrt->addRenderable(surf->impl());
        *pSurface = getHandle(surf);
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_add_vector_field_to_chart(fg_vector_field* pField, fg_chart pChart, const unsigned pNPoints, const fg_dtype pType)
{
    try
    {
        ARG_ASSERT(1, (pChart != nullptr));
        ARG_ASSERT(2, (pNPoints > 0));

        common::Chart*       chrt  = getChart(pChart);
        common::VectorField* field = new common::VectorField(pNPoints, (forge::dtype)pType, chrt->chartType());
        chrt->addRenderable(field->impl());
        *pField = getHandle(field);
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_remove_image_from_chart(fg_chart pChart, fg_image pImage)
{
    try
    {
        ARG_ASSERT(0, (pChart != nullptr));
        ARG_ASSERT(1, (pImage != nullptr));

        common::Image* img = getImage(pImage);
        getChart(pChart)->removeRenderable(img->impl());
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_remove_histogram_from_chart(fg_chart pChart, fg_histogram pHistogram)
{
    try
    {
        ARG_ASSERT(0, (pHistogram != nullptr));
        ARG_ASSERT(1, (pChart != nullptr));

        common::Chart* chrt = getChart(pChart);

        common::Histogram* hist = getHistogram(pHistogram);
        chrt->removeRenderable(hist->impl());
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_remove_plot_from_chart(fg_chart pChart, fg_plot pPlot)
{
    try
    {
        ARG_ASSERT(0, (pPlot != nullptr));
        ARG_ASSERT(1, (pChart != nullptr));

        common::Chart* chrt = getChart(pChart);

        common::Plot* plt = getPlot(pPlot);
        chrt->removeRenderable(plt->impl());
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_remove_surface_from_chart(fg_chart pChart, fg_surface pSurface)
{
    try
    {
        ARG_ASSERT(0, (pSurface != nullptr));
        ARG_ASSERT(1, (pChart != nullptr));

        common::Chart* chrt = getChart(pChart);

        common::Surface* surf = getSurface(pSurface);
        chrt->removeRenderable(surf->impl());
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_remove_vector_field_from_chart(fg_chart pChart, fg_vector_field pField)
{
    try
    {
        ARG_ASSERT(0, (pField != nullptr));
        ARG_ASSERT(1, (pChart != nullptr));

        common::Chart*       chrt  = getChart(pChart);
        common::VectorField* field = getVectorField(pField);
        chrt->removeRenderable(field->impl());
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_render_chart(const fg_window pWindow, const fg_chart pChart, const int pX, const int pY, const int pWidth, const int pHeight)
{
    try
    {
        ARG_ASSERT(0, (pWindow != nullptr));
        ARG_ASSERT(1, (pChart != nullptr));
        ARG_ASSERT(2, (pX >= 0));
        ARG_ASSERT(3, (pY >= 0));
        ARG_ASSERT(4, (pWidth > 0));
        ARG_ASSERT(5, (pHeight > 0));

        getChart(pChart)->render(getWindow(pWindow)->getID(), pX, pY, pWidth, pHeight, IDENTITY, IDENTITY);
    }
    CATCHALL

    return FG_ERR_NONE;
}

fg_err fg_get_chart_type(fg_chart_type* pChartType, const fg_chart pChart)
{
    try
    {
        ARG_ASSERT(1, (pChart != nullptr));

        *pChartType = getChart(pChart)->chartType();
    }
    CATCHALL

    return FG_ERR_NONE;
}
