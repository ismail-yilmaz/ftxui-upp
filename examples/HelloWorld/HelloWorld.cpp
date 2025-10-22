#include <FTXUI/FTXUI.h>

using namespace ftxui;

int main()
{
    auto screen = ScreenInteractive::Fullscreen();
    
    auto component = Renderer([] {
        return vbox({
            text("Hello World, FTXUI rocks!")
            | bold | blink | hcenter | vcenter | color(Color::Green) | border | flex
        });
    });
    
    component |= CatchEvent([&](Event event) {
        if (event.is_character() || event == Event::Escape) {
            screen.Exit();
            return true;
        }
        return false;
    });
    
    screen.Loop(component);
    return 0;
}