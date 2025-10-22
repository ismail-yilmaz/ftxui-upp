// FTXUI package for U++
// Copyright 2025, İsmail Yılmaz

#ifndef _FTXUI_FTXUI_h_
#define _FTXUI_FTXUI_h_

// Screen
#include  "ftxui/include/ftxui/screen/box.hpp"
#include  "ftxui/include/ftxui/screen/color.hpp"
#include  "ftxui/include/ftxui/screen/color_info.hpp"
#include  "ftxui/include/ftxui/screen/image.hpp"
#include  "ftxui/include/ftxui/screen/pixel.hpp"
#include  "ftxui/include/ftxui/screen/screen.hpp"
#include  "ftxui/include/ftxui/screen/string.hpp"
#include  "ftxui/include/ftxui/screen/terminal.hpp"
#include  "ftxui/include/ftxui/screen/deprecated.hpp"

// Dom
#include  "ftxui/include/ftxui/dom/canvas.hpp"
#include  "ftxui/include/ftxui/dom/direction.hpp"
#include  "ftxui/include/ftxui/dom/elements.hpp"
#include  "ftxui/include/ftxui/dom/flexbox_config.hpp"
#include  "ftxui/include/ftxui/dom/linear_gradient.hpp"
#include  "ftxui/include/ftxui/dom/node.hpp"
#include  "ftxui/include/ftxui/dom/requirement.hpp"
#include  "ftxui/include/ftxui/dom/selection.hpp"
#include  "ftxui/include/ftxui/dom/table.hpp"
#include  "ftxui/include/ftxui/dom/take_any_args.hpp"
#include  "ftxui/include/ftxui/dom/deprecated.hpp"

// Component
#include  "ftxui/include/ftxui/component/animation.hpp"
#include  "ftxui/include/ftxui/component/captured_mouse.hpp"
#include  "ftxui/include/ftxui/component/component.hpp"
#include  "ftxui/include/ftxui/component/component_base.hpp"
#include  "ftxui/include/ftxui/component/component_options.hpp"
#include  "ftxui/include/ftxui/component/event.hpp"
#include  "ftxui/include/ftxui/component/loop.hpp"
#include  "ftxui/include/ftxui/component/mouse.hpp"
#include  "ftxui/include/ftxui/component/receiver.hpp"
#include  "ftxui/include/ftxui/component/screen_interactive.hpp"
#include  "ftxui/include/ftxui/component/task.hpp"

namespace Upp {
	
using TuiScreen            = ftxui::Screen;
using TuiInteractiveScreen = ftxui::ScreenInteractive;
using TuiElement           = ftxui::Element;
using TuiComponent         = ftxui::Component;
using TuiDecorator         = ftxui::Decorator;
using TuiColor             = ftxui::Color;
using TuiPixel             = ftxui::Pixel;
using TuiEvent             = ftxui::Event;
using TuiTask              = ftxui::Task;

}

#endif
