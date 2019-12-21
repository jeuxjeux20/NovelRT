// Copyright © Matt Jones and Contributors. Licensed under the MIT License (MIT). See LICENCE.md in the repository root for more information.

#ifndef NOVELRT_GRAPHICS_BASICFILLRECT_H
#define NOVELRT_GRAPHICS_BASICFILLRECT_H

#include "RenderObject.h"
#include "RGBAConfig.h"
#include "ShaderProgram.h"
#include "NovelCamera.h"

namespace NovelRT::Graphics {
  class BasicFillRect : public RenderObject {

  private:
    RGBAConfig _colourConfig;
    Lazy<GLuint> _colourBuffer;
    std::vector<GLfloat> _colourData;

  protected:
    void configureObjectBuffers() final;

  public:
    BasicFillRect(LayeringService* layeringService,
                       const RGBAConfig& fillColour,
                       const CommonArgs& args,
                       ShaderProgram shaderProgram,
                       Camera* camera);

    void drawObject() final;
    RGBAConfig getColourConfig() const;
    void setColourConfig(const RGBAConfig& value);
  };
}

#endif //NOVELRT_GRAPHICS_BASICFILLRECT_H