import numpy as np

from sdnoise import sdnoise2

SIZE     = 2048
OFFSET_X = 53.36
OFFSET_Y = 138.64

SCALE       = 0.0025
PERSISTANCE = 0.5
LUNACRACITY = 2.0
OCTAVES     = 6

# control the erosive noise
ALPHA = 0.15 # feature displacement
BETA  = 1.10 # roughness near valeys

def erosive_noise(x, y) -> float:
    px = x * SCALE
    py = y * SCALE

    freq = 1.0
    amp = 1.0
    B = 0.0
    dx = 0.0
    dy = 0.0
    s = 1.0

    for j in range(OCTAVES):
        pre_x = freq * (px + dx)
        pre_y = freq * (py + dy)

        n, gx, gy = sdnoise2(pre_x, pre_y)
        t_in = s * (1 - abs(n))
        B = B + (amp * t_in)

        # aproximate gradient because 1 - abs(N(p))
        grad_x = -n * gx
        grad_y = -n * gy

        dx = dx + (amp * ALPHA * s * grad_x)
        dy = dy + (amp * ALPHA * s * grad_y)
        s = s * min(1, max(0, BETA * B))

        amp = amp * PERSISTANCE
        freq = freq * LUNACRACITY

    return B

def main():
    hf = np.zeros((SIZE, SIZE), dtype=np.float32)

    for x in range(0, SIZE):
        for y in range(0, SIZE):
            hf[x, y] = erosive_noise(x + OFFSET_X, y + OFFSET_Y)

    np.savetxt("noise.txt", hf)

    return 0

if __name__ == "__main__":
    main()
