#include <iostream>
#include <fstream>
#include <vector>

// Define a vertex structure to hold the coordinates
struct Vertex {
    float x, y, z;
    Vertex(float x, float y, float z) : x(x), y(y), z(z) {}
};

// Function to write the pyramid to an .obj file
void writePyramidToObj(const std::string& filename) {
    // Define the vertices of the pyramid (base and apex)
    std::vector<Vertex> vertices = {
        { -1.0f, 0.0f, -1.0f }, // Base vertex 1
        {  1.0f, 0.0f, -1.0f }, // Base vertex 2
        {  1.0f, 0.0f,  1.0f }, // Base vertex 3
        { -1.0f, 0.0f,  1.0f }, // Base vertex 4
        {  0.0f, 1.0f,  0.0f }  // Apex
    };

    // Define the faces of the pyramid (each face is a triangle)
    std::vector<std::vector<int>> faces = {
        { 1, 2, 5 }, // Triangle 1 (base vertex 1, base vertex 2, apex)
        { 2, 3, 5 }, // Triangle 2
        { 3, 4, 5 }, // Triangle 3
        { 4, 1, 5 }, // Triangle 4
        { 1, 2, 3, 4 } // Base (quadrilateral, split into two triangles)
    };

    // Create and open the output file
    std::ofstream objFile(filename);
    
    if (!objFile.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }

    // Write vertices to the file
    for (const auto& vertex : vertices) {
        objFile << "v " << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;
    }

    // Write faces to the file (1-based indexing in .obj files)
    for (const auto& face : faces) {
        objFile << "f";
        for (int idx : face) {
            objFile << " " << idx;
        }
        objFile << std::endl;
    }

    objFile.close();
    std::cout << "Pyramid saved to " << filename << std::endl;
}

int main() {
    // Specify the output file name
    std::string filename = "pyramid.obj";

    // Write the pyramid to the .obj file
    writePyramidToObj(filename);

    return 0;
}
