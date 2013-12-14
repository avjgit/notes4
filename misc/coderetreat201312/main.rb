
def to_Mandelbrot(point_x, point_y, screen_x, screen_y)
    range_x = 3.5
    range_y = 2.0
    return [point_x * (range_x / screen_x) - range_x/2,
            point_y * (range_y / screen_y) - range_y/2]
end

def is_in_Mandelbrot(point_x, point_y)
    max_iteration = 1000
    x = 0.0
    y = 0.0

    iteration = 0
    # while (x < 3) doq
    while ( (x*x + y*y < 2*2)  &&  (iteration < max_iteration) ) do
        xtemp = x*x - y*y + point_x
        y = 2*x*y + point_y
        x = xtemp
        iteration = iteration + 1
    end
    return iteration >= max_iteration
end

def print_mandelbrot
    screen_x = 80
    screen_y = 40
    point = Array.new
    for x in 0..screen_x do
        for y in 0..screen_y do
            point = to_Mandelbrot(x, y, screen_x, screen_y)
            inside = is_in_Mandelbrot(point[0], point[1])
            print inside ? 'X' : ' '
        end
        p
    end
end

def test_to_mandelbrot

    screen_x = 80;
    screen_y = 40;

    point_x = screen_x / 2;
    point_y = screen_y / 2;

    point = Array.new

    point = to_Mandelbrot(point_x, point_y, screen_x, screen_y)
    p point

    return (point[0] == 0 && point[1] == 0) ? 'passed' : 'failed'
end

def test_in_mandelbrot_positive
    return is_in_Mandelbrot(0, 0) ? 'passed' : 'failed'
end

def test_in_mandelbrot_negative
    return is_in_Mandelbrot(-1, 1) ? 'failed' : 'passed'
end

def test_in_mandelbrot_negative2
    return is_in_Mandelbrot(-0.8, 0.5) ? 'failed' : 'passed'
end

# p test_mandelbrot
# p test_in_mandelbrot_positive
# p test_in_mandelbrot_negative
# p test_in_mandelbrot_negative2
print_mandelbrot