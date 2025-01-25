import bpy
import bmesh

# Create a new mesh and object
mesh = bpy.data.meshes.new("TriangleMesh")
obj = bpy.data.objects.new("TriangleObject", mesh)
bpy.context.collection.objects.link(obj)

# Define vertices and faces
vertices = [(-0.5, -0.5, 0), (0.5, -0.5, 0), (0.0, 0.5, 0)]
faces = [(0, 1, 2)]

# Create mesh
mesh.from_pydata(vertices, [], faces)
mesh.update()
