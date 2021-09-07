#include "svg.h"


void
svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}


void
svg_end()
{
    cout << "</svg>\n";
}


void
svg_text(double left, double baseline , string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'>"<<text<<"</text>"<<endl;
}


void
svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x='" << x << "' y='" << y <<"' width='"<< width <<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"' />" << endl;
}

void
show_histogram_svg(const vector<size_t>& bins, size_t& bin_height)
{
     if (bins.size() == 0)
    {
        return;
    }
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 15;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_HEIGHT = 30;
    const auto BIN_WIDTH = 30;
    const auto BLOCK_HEIGHT = 10;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double left = 0;
    size_t max_count = bins[0];
    for (size_t count : bins)
    {
        if ( count > max_count)
            {
                max_count=count;
            }
    }
    for (size_t bin : bins)
    {
        const double scaling_factor = (double)(IMAGE_HEIGHT - TEXT_HEIGHT) / max_count;
        bin_height=(size_t)(bin*scaling_factor);

        svg_text(left + TEXT_LEFT, TEXT_BASELINE, to_string(bin));
        svg_rect(left, TEXT_HEIGHT, BIN_WIDTH, bin_height, "white", "#c71585" );
        left += BIN_WIDTH;
    }
    svg_end();
}
