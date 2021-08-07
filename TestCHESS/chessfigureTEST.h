#pragma once
#include <tuple>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "chessfigure.h"


using namespace testing;

TEST(ChessFigureTEST, Constructor_getter_TEST)
{

    gameitems::ChessFigure figure(gameitems::ChessFigure::ColorFigure::BLACK, gameitems::ChessFigure::TypeFigure::BISHOP);
    auto tmp = std::make_tuple(gameitems::ChessFigure::ColorFigure::BLACK, gameitems::ChessFigure::TypeFigure::BISHOP);

    ASSERT_EQ(figure.get_figure(), (tmp));
}
