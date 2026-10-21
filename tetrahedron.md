4 triangles (Tetrahedron), per triangle 3 points, per point 3 positional values -> 36 positional vertices

// Triangle 1
x.xf, x.xf, x.xf // OpenGL takes the first three vertices as one triangle and follows it in order.
x.xf, x.xf, x.xf // Note I need 7 arguments
x.xf, x.xf, x.xf

//triangle 2
x.xf, x.xf, x.xf
x.xf, x.xf, x.xf
x.xf, x.xf, x.xf

Step 1: Define vertices for the tetrahedron (Either trig or every second edge of a cube)
Step 2: Create an object that takes and sends the vertices to render
Step 3: Make Adjustable properties to said Object, move it rotate it ect.