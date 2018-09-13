//
// Created by Francesco Gradi on 07/09/18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

#include "../MainFrame.h"

class MainFrameSuite : public ::testing::Test {


};

TEST(MainFrameSuite, OpenClose) {

    MainFrame* mainFrame = new MainFrame("Main menu", wxPoint(50, 50), wxSize(400,200));
    mainFrame->Show(true);

    ASSERT_EQ(mainFrame->IsShown(), 1);

    wxCommandEvent* event = new wxCommandEvent();
    mainFrame->OnExit(*event);

    ASSERT_EQ(mainFrame->IsShown(), 0);
}


