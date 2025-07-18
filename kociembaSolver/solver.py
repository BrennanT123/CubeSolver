import twophase.solver  as sv
import serial
import time

port = '/dev/ttyACM0'
ser = serial.Serial(port, 9600)
time.sleep(2)
cube_state = ""

while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').strip()
        print("Received:", line)
        if line.startswith('Solve:'):
            cubestring = line.split(':')[1].strip()
            solution = sv.solve(cubestring,19,2)
            spreadSolution = ""
            moves = solution.split()
            for move in moves:
             if(move[0]== "("):
                continue
             for i in range(int(move[1])):
                spreadSolution += move[0]
            ser.write(spreadSolution.encode('utf-8') + b'\n')
            print("Solution sent:", spreadSolution)


# # cubestring = 'DUUBULDBFRBFRRULLLBRDFFFBLURDBFDFDRFRULBLUFDURRBLBDUDL'
# # 'FRUFURUBL FDBLRFRUB RRDUFULLF DBDDDRRFU LUFBLBDLB LFULBDRDB'
# cubestring = 'FRUFURUBLFDBLRFRUBRRDUFULLFDBDDDRRFULUFBLBDLBLFULBDRDB'

# # # gives a solution with max length 19 timout 2 seconds
# solution = sv.solve(cubestring,19,2)
# print("Solution:", solution)