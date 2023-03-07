/*
 * Xournal++
 *
 * This file is part of the Xournal UnitTests
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#include <config-test.h>
#include <gtest/gtest.h>

#include "model/StrokeStyle.h"

namespace {
constexpr double dashLinePattern[] = {6, 3};
constexpr double dashDotLinePattern[] = {6, 3, 0.5, 3};
constexpr double dotLinePattern[] = {0.5, 3};
constexpr double custPattern[] = {0.01, -1.0, 0.005};
}

TEST(StrokeStyle, testParseStyle)
{
    EXPECT_EQ(StrokeStyle::parseStyle("random"), LineStyle());
    EXPECT_EQ(StrokeStyle::parseStyle("cust: "), LineStyle());
    
    LineStyle l1;
    double testData[] = {100, 200, 300};
    l1.setDashes(testData, 3);
    EXPECT_EQ(StrokeStyle::parseStyle("cust: 100 200 300"), l1);
}

TEST(StrokeStyle, testFormatStyle)
{
    LineStyle dashLine;
    dashLine.setDashes(dashLinePattern, 2);
    EXPECT_EQ(StrokeStyle::formatStyle(dashLine), "dash");    

    LineStyle dashDot;
    dashDot.setDashes(dashDotLinePattern, 4);
    EXPECT_EQ(StrokeStyle::formatStyle(dashDot), "dashdot");    

    LineStyle dotLine;
    dotLine.setDashes(dotLinePattern, 2);
    EXPECT_EQ(StrokeStyle::formatStyle(dotLine), "dot");    

    LineStyle custLine;
    custLine.setDashes(custPattern, 3);
    EXPECT_EQ(StrokeStyle::formatStyle(custLine), "cust: 0.01 -1.00 0.01");
}
