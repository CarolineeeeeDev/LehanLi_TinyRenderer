#include "tgaimage.h"


const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color);

int main(int argc, char** argv) {
    TGAImage image(500, 500, TGAImage::RGB);
    line(-100, -100, 500, 500, image, white);
    line(40, 40, 60, 260, image, white);
    line(40, 40, 260, 60, image, white);
    image.write_tga_file("output.tga");
    return 0;
}

void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color)
{
    bool steep = false;
    if (std::abs(x0 - x1) < std::abs(y0 - y1))
    {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    int dx = x1 - x0;
    int dy = y1 - y0;
    float derror = std::abs(dy) * 2;//
    float error = 0;
    int y = y0;
    for (int x = x0; x <= x1; x++)
    {
        if (steep)
        {
            image.set(y, x, color);
        }
        else
        {
            image.set(x, y, color);
        }
        error += derror;
        if (error > dx)
        {
            y += (y1 > y0 ? 1 : -1);
            error -= dx * 2;
        }
    }
}