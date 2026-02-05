from collections import deque

class StaggerSim:
    def __init__(self, N, adder_delay=1):
        self.N = N
        self.adder_delay = adder_delay

        self.fifos = [deque() for slot in range(N)]
        self.delay = [0]*N #counter delay until begin popping
        self.armed = [False]*N # allowed to pop yet?

        self.matrix = None #current matrix being streamed
        self.input_col = 0 #which column we’re pushing
        self.active_tile = False #whether a matrix is currently in progress

        self.cycle = -1

    def start_tile(self, matrix):
        self.matrix = matrix
        self.input_col = 0
        self.active_tile = True #new tile

        for r in range(self.N):
            self.delay[r] = self.adder_delay * r
            if r == 0:
                self.armed[r] = True
            else:
                self.armed[r] = False

    def step(self):
        self.cycle += 1

        #push inputs
        if self.active_tile and self.input_col < self.N: #tile is active and cols remain
            for r in range(self.N):
                self.fifos[r].append(self.matrix[r][self.input_col])
            self.input_col += 1

        #issuing
        out = [0]*self.N

        for r in range(self.N):
            if not self.armed[r]: 
                if self.delay[r] > 0:
                    self.delay[r] -= 1
                else:
                    self.armed[r] = True
            else: #counted down, can pop now
                if self.fifos[r]:
                    out[r] = self.fifos[r].popleft()

        #tile finished?
        if (
            self.active_tile and
            self.input_col >= self.N and
            all(len(f)==0 for f in self.fifos)
        ):
            self.active_tile = False

        return out

def main():
    N = 6
    A = [[1,2,3,4,5,6], [7,8,9,1,2,3],[1,2,3,4,5,6],[7,8,9,1,2,3],[1,2,3,4,5,6],[7,8,9,1,2,3]]
    B = [[1,2,3,4,5,6], [7,8,9,1,2,3],[1,2,3,4,5,6],[7,8,9,1,2,3],[1,2,3,4,5,6],[7,8,9,1,2,3]]
    #A = [[r*10+c for c in range(1,N+1)] for r in range(1,N+1)]
    #B = [[100+r*10+c for c in range(1,N+1)] for r in range(1,N+1)]

    sim = StaggerSim(N, adder_delay=2)

    sim.start_tile(A)

    for x in range(30):
        print(f"cycle {sim.cycle+1:02d}:", sim.step())

    sim.start_tile(B)

    for x in range(30):
        print(f"cycle {sim.cycle+1:02d}:", sim.step())

if __name__ == "__main__":
    main()
