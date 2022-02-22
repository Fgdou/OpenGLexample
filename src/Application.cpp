//
// Created by fgdou on 2/21/22.
//

#include <stdexcept>
#include <iostream>
#include "helper.h"
#include "Application.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Block.h"


Application::Application(){
//    vb.setData(std::vector<float>{
//            -0.5f, -0.5f, 0.0f, 0.0f,
//            0.5f, -0.5f, 1.0f, 0.0f,
//            -0.5f, 0.5f, 0.0f, 1.0f,
//            0.5f, 0.5f, 1.0f, 1.0f,
//    });
//    ib.setData(std::vector<uint32_t>{
//            0, 1, 2,
//            1, 2, 3,
//    });
//    bd.addType<float>(2);
//    bd.addType<float>(2);
//
//    program.addShader("../shaders/simple.vert", Program::VERTEX);
//    program.addShader("../shaders/simple.frag", Program::FRAGMENT);
//    program.compile();
//    program.bind();
}

void Application::run() {
    Block block{{0, 0, -3}, {0, 0}};
    Camera cam{{0, 0, 0}, {0, 0}, 90, window->getRatio()};
    while(!window->shouldClose()){

        if(window->hasResized())
            cam.updateRatio(window->getRatio());

        i += di;
//
//        texture.bind(0);
//
//        auto rotate = glm::rotate(glm::mat4(1.0f), i, glm::vec3{0.0, 1.0, 0.0});
//        auto translate = glm::translate(glm::mat4(1.0f), glm::vec3{0.0f, 0.0f, 0.0f});
//        auto mvp = rotate * translate;
//
//        program.setUniform("MVP", mvp);
//
//        window.clear();
//        renderer.render(window, program, bd, vb, ib);
//        window.draw();

        block.getRot() = glm::vec2{0, i};

        window->clear();
        block.draw(*window, renderer, cam);
        window->draw();
    }
}