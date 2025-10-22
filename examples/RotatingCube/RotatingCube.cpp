#include <plugin/FTXUI/FTXUI.h>
#include <Xform3D/Xform3D.h>

using namespace Upp;
using namespace ftxui;

CONSOLE_APP_MAIN
{
	auto screen = ScreenInteractive::Fullscreen();
	
	Point3D angles;
	double  scale = 100.0;
	
	Vector<Point3D> vertices = {
		{ -1, -1, -1 }, { 1, -1, -1 }, { 1, 1, -1 }, { -1, 1, -1 },
		{ -1, -1,  1 }, { 1, -1,  1 }, { 1, 1,  1 }, { -1, 1,  1 }
	};
	
	Vector<Tuple<int, int>> edges = {
		{0, 1}, {1, 2}, {2, 3}, {3, 0},
		{4, 5}, {5, 6}, {6, 7}, {7, 4},
		{0, 4}, {1, 5}, {2, 6}, {3, 7}
	};
	
	auto renderer = Renderer([&]() -> Element {
		Size canvassize(100, 100);
		auto c = Canvas(canvassize.cx, canvassize.cy);
		
		Matrix4D transform = Matrix4D::Rotation(angles);
		
		// Project vertices to screen coordinates
		auto Project = [&](const Point3D& p) -> Pointf {
			return Pointf(canvassize / 2.0) + (p * (scale / (p.z + 4.0))).ToPointf();
		};
		// Transform and project vertices
		Vector<Pointf> projected;
		for(const auto& v : vertices) {
			Point3D rotated = v * transform;
			projected << Project(rotated);
		}
		
		// Draw edges
		for(const auto& [a, b] : edges) {
			Pointf p1 = projected[a];
			Pointf p2 = projected[b];
			c.DrawPointLine((int) p1.x, (int) p1.y, (int) p2.x, (int) p2.y);
		}
		
		// Draw vertices
		for(const auto& p : projected)
			c.DrawPoint((int) p.x, (int) p.y, true);
		
		return vbox({
			text(t_("Rotating 3D Cube")) | bold | center,
			text(t_("Press 'q' to quit, 'p' to pause")) | center,
			text(t_("Zoom in: '+', Zoom out: '-', Reset: '*'")) | center,
			canvas(c) | flex | center | border
		});
	});
	
	bool paused = false;
	
	auto component = CatchEvent(renderer, [&](TuiEvent event) {
		if(event == TuiEvent::Character('q')) {
			screen.ExitLoopClosure()();
			return true;
		}
		else
		if(event == TuiEvent::Character('p')) {
			paused = !paused;
			return true;
		}
		else
		if(event == TuiEvent::Character('+')) {
			scale += 5.0;
			return true;
		}
		else
		if(event == TuiEvent::Character('-')) {
			scale -= 5.0;
			return true;
		}
		else
		if(event == TuiEvent::Character('*')) {
			scale = 100.0;
			return true;
		}
		return false;
	});
	
	CoWork cw;
	cw & [&] {
		while(!CoWork::IsCanceled()) {
			if(!paused) {
				angles += { 0.03, 0.02, 0.01 };
				screen.Post(TuiEvent::Custom);
			}
			Sleep(20);
		}
	};
	
	screen.Loop(component);
	cw.Cancel();
}