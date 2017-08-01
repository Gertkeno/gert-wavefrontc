# gert-wavefrontc
Converts .obj wavefront files to compileable C code, like xxd -i but a bit nicer, also might be useless to anyone but me!

This program will make 4 arrays for vertices, texture maps, normals, and faces, it will assume you have all four in your wavefront file.

Accessing these arrays is easy, just extern float \*FILENAME_vert for vertices, FILENAME_uv for texture maps, FILENAME_norm for normals, and FILENAME_face for faces.
Lastly there is FILENAME_len which counts how many vertexs faces requires.

I've only tested this project building 3D models in an inefficient way, but the data is all there so you should be able to do most anything with it; at least what ever a wavefront file would let you.
