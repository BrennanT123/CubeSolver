import pyray as pr
import configs
from cube import Rubik
import sys as sys

#setup
pr.init_window(configs.win_w, configs.win_h, "Rubiks Cube")
pr.set_target_fps(configs.fps)

#generating the cube

rubiksCube = Rubik()
piece = rubiksCube.generate_rubik(size=4)

while not pr.window_should_close():
    pr.update_camera(configs.camera, pr.CameraMode.CAMERA_ORBITAL)

    pr.begin_drawing()
    pr.clear_background(pr.RAYWHITE)
    
    position = pr.Vector3(piece.center[0],piece.center[1],piece.center[2])
    pr.draw_model(piece.model, position, 2 , piece.face_color)
    pr.begin_mode_3d(configs.camera)
    pr.draw_grid(20,1.0)

    pr.end_mode_3d()
    pr.end_drawing()
    
    
pr.close_window()