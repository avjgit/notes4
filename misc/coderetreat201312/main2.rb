def is_in_manelbrot(x0, y0)
  x = 0.0
  y = 0.0
  iteration = 0
  max_iteration = 1000
  while ( x*x + y*y < 2*2  &&  iteration < max_iteration ) do
    xtemp = x*x - y*y + x0
    y = 2*x*y + y0
    x = xtemp
    iteration = iteration + 1
  end
  return iteration >= max_iteration
end

def test_is_in_mandelbrot
    return is_in_manelbrot(0, 0) ? 'passed' : 'failed'
end

def convert_to_mandelbrot_coord(x, y)
    mandelbrot_x_scale = [-2.5, 1.0]
    mandelbrot_y_scale = [-1.0, 1.0]
    x_range = mandelbrot_x_scale[1] - mandelbrot_x_scale[0]
    y_range = mandelbrot_y_scale[1] - mandelbrot_y_scale[0]
    return [(x / 10) - 3, (y / -5) + 2 ]
end

def test_convert_to_mandelbrot_coord
    return convert_to_mandelbrot_coord(30, 10) == [0, 0] ? 'passed' : 'failed'
end

def draw_mandelbrot
    p = Array.new
    20.times do |y|
        60.times do |x|
            p = convert_to_mandelbrot_coord(x, y)
            print is_in_manelbrot(p[0], p[1]) ? 'X' : '_'
        end
        puts
    end
end


# p test_is_in_mandelbrot
# p test_convert_to_mandelbrot_coord
draw_mandelbrot
