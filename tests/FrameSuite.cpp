//
// Created by Francesco Gradi on 13/09/18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

#include "../Frame.h"
#include "../LoadingHandler.h"

class FrameSuite: public ::testing::Test {

};

TEST(FrameSuite, OpenClose) {

    Frame* frame = new Frame(nullptr);
    frame->Show(true);

    ASSERT_EQ(frame->IsShown(), 1);

    wxCommandEvent* event = new wxCommandEvent();
    frame->OnExit(*event);

    ASSERT_EQ(frame->IsShown(), 0);

    frame->Destroy();
}

TEST(FrameSuite, CloseLoading) {

    Frame* frame = new Frame(nullptr);
    frame->Show(true);

    LoadingHandler* loadingHandler = new LoadingHandler();

    loadingHandler->add(frame);
    frame->setLoadingHandler(loadingHandler);

    loadingHandler->download(0, 5);

    wxCommandEvent* event = new wxCommandEvent();
    frame->OnExit(*event);

    ASSERT_EQ(frame->IsShown(), 0);

    frame->Destroy();
    delete loadingHandler;
}

TEST(FrameSuite, StopLoading) {
    Frame* frame = new Frame(nullptr);
    frame->Show(true);

    LoadingHandler* loadingHandler = new LoadingHandler();

    loadingHandler->add(frame);
    frame->setLoadingHandler(loadingHandler);

    loadingHandler->download(0, 5);

    ASSERT_EQ(frame->getIsActive(), true);

    wxCommandEvent* event = new wxCommandEvent();
    frame->buttonStopClicked(*event);

    ASSERT_EQ(frame->getIsActive(), false);

    event = new wxCommandEvent();
    frame->OnExit(*event);

    frame->Destroy();
    delete loadingHandler;
}

TEST(FrameSuite, ResumeLoading) {
    Frame* frame = new Frame(nullptr);
    frame->Show(true);

    LoadingHandler* loadingHandler = new LoadingHandler();

    loadingHandler->add(frame);
    frame->setLoadingHandler(loadingHandler);

    loadingHandler->download(0, 5);

    ASSERT_EQ(frame->getIsActive(), true);

    wxCommandEvent* event = new wxCommandEvent();
    frame->buttonStopClicked(*event);

    ASSERT_EQ(frame->getIsActive(), false);

    event = new wxCommandEvent();
    frame->buttonResumeClicked(*event);

    ASSERT_EQ(frame->getIsActive(), true);

    event = new wxCommandEvent();
    frame->OnExit(*event);

    frame->Destroy();
    delete loadingHandler;
}