
def to_Mandelbrot(point_x, point_y, screen_x, screen_y)
    range_x = 3.5
    range_y = 2.0
    point = Array.new
    point[0] = point_x * (range_x / screen_x) - range_x/2
    point[1] = point_y * (range_y / screen_y) - range_y/2
    return point
end

def test_mandelbrot

    screen_x = 80;
    screen_y = 40;

    point_x = screen_x / 2;
    point_y = screen_y / 2;

    point = Array.new

    point = to_Mandelbrot(point_x, point_y, screen_x, screen_y)
    p point

    return (point[0] == 0 && point[1] == 0) ? 'passed' : 'failed'

end

p test_mandelbrot
