# gert-wavefrontc
Converts .obj wavefront files to compileable C code, like xxd -i but a bit nicer, also might be useless to anyone but me!

This program will make 4 arrays for vertexs, texture maps, normals, and faces, it will assume you have all four in your wavefront file.
accessing these arrays is easy, just extern FILENAME_vert for vertexs, FILENAME_uv for texture maps, FILENAME_norm for normals, and FILENAME_face for faces.
lastly there is FILENAME_len which counts how many vertexs faces requires.
