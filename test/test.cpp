#include <agg_pixfmt_rgb.h>
#include <agg_renderer_base.h>
#include <platform/agg_platform_support.h>

class the_application : public agg::platform_support
{
public:
	the_application(agg::pix_format_e format, bool flip_y) :
		agg::platform_support(format, flip_y),
		pix_fmt(rbuf_window()),
		ren_bas(pix_fmt) //≥ı ºªØ‰÷»æ∆˜
	{ }

	virtual void on_draw()
	{
		ren_bas.reset_clipping(true);
		ren_bas.clear(agg::rgba8(204, 204, 204));
	}

private:
	agg::pixfmt_rgb24 pix_fmt;
	agg::renderer_base<agg::pixfmt_rgb24> ren_bas;

};

int agg_main(int argc, char* argv[])
{
	the_application app(agg::pix_format_rgb24, true);
	app.caption("AGG Test");

	if (app.init(500, 200, agg::window_resize)) {
		return app.run();
	}
	return -1;
}