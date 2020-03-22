// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.
#include "NovelRT.h"


#ifndef NOVELRT_MATHS_GEOVECTOR2F_H
#define NOVELRT_MATHS_GEOVECTOR2F_H

#ifdef __cplusplus
extern "C" {
#endif

 struct GeoVector2F {
   float x;
   float y;
 };

typedef struct GeoVector2F GeoVector2_t;

GeoVector2_t GeoVector2F_create(float x, float y) {
  GeoVector2_t gv = { x, y };
  return gv;
}

inline const GeoVector2_t GeoVector2F_uniform(float value) {
  return GeoVector2F_create(value, value);
}

inline const GeoVector2_t GeoVector2F_zero() {
  return GeoVector2F_uniform(0.0f);
}

inline const GeoVector2_t GeoVector2F_one() {
  return GeoVector2F_uniform(1.0f);
}

float GeoVector2F_getX(GeoVector2_t& gv) {
  return gv.x;
}

void GeoVector2F_setX(GeoVector2_t& gv, float value) {
  gv.x = value;
}

float GeoVector2F_getY(GeoVector2_t& gv) {
  return gv.y;
}

void GeoVector2F_setY(GeoVector2_t& gv, float value) {
  gv.y = value;
}

void GeoVector2F_rotateToAngleAroundPoint(GeoVector2F& vector, float angleRotationValue, const GeoVector2F& point) noexcept {
  NovelRT::Maths::GeoVector2<float> geo = NovelRT::Maths::GeoVector2<float>(vector.x, vector.y);
  geo.rotateToAngleAroundPoint(angleRotationValue, NovelRT::Maths::GeoVector2<float>(point.x, point.y));
  vector.x = geo.getX();
  vector.y = geo.getY();
  //vec2Value() = glm::rotate((vec2Value() - point.vec2Value()), glm::radians(angleRotationValue)) + point.vec2Value();
}

bool GeoVector2F_epsilonEquals(GeoVector2F& vector, const GeoVector2F& other, const GeoVector2F& epsilonValue) noexcept {
  NovelRT::Maths::GeoVector2<float>v1 = NovelRT::Maths::GeoVector2<float>(vector.x, vector.y);
  NovelRT::Maths::GeoVector2<float>v2 = NovelRT::Maths::GeoVector2<float>(other.x, other.y);
  NovelRT::Maths::GeoVector2<float>v3 = NovelRT::Maths::GeoVector2<float>(epsilonValue.x, epsilonValue.y);
  return v1.epsilonEquals(v2, v3);
  //return glm::all(glm::equal(vec2Value(), other.vec2Value(), epsilonValue.vec2Value()));
}

inline GeoVector2_t GeoVector2F_getNormalised(GeoVector2_t& gv) {
  NovelRT::Maths::GeoVector2<float> geo = NovelRT::Maths::GeoVector2<float>(gv.x, gv.y).getNormalised();
  GeoVector2_t normal = {geo.getX(), geo.getY()};
  return normal;
}

inline float GeoVector2F_getLength(GeoVector2_t& gv) {
  NovelRT::Maths::GeoVector2<float> geo = NovelRT::Maths::GeoVector2<float>(gv.x, gv.y);
  return geo.getLength();
}

inline float GeoVector2F_getMagnitude(GeoVector2_t& gv) {
  return GeoVector2F_getLength(gv);
}

inline bool GeoVector2F_equal(const GeoVector2_t& first, const GeoVector2_t& other) {
  return NovelRT::Maths::GeoVector2<float>(first.x, first.y) == NovelRT::Maths::GeoVector2<float>(other.x, other.y);
}

inline bool GeoVector2F_notEqual(const GeoVector2_t& first, const GeoVector2_t& other) {
  return NovelRT::Maths::GeoVector2<float>(first.x, first.y) != NovelRT::Maths::GeoVector2<float>(other.x, other.y);
}

inline bool GeoVector2F_lessThan(const GeoVector2_t& first, const GeoVector2_t& other) {
  return NovelRT::Maths::GeoVector2<float>(first.x, first.y) < NovelRT::Maths::GeoVector2<float>(other.x, other.y);
}

inline bool GeoVector2F_lessThanOrEqualTo(const GeoVector2_t& first, const GeoVector2_t& other) {
  return NovelRT::Maths::GeoVector2<float>(first.x, first.y) <= NovelRT::Maths::GeoVector2<float>(other.x, other.y);
}

inline bool GeoVector2F_greaterThan(const GeoVector2_t& first, const GeoVector2_t& other) {
  return NovelRT::Maths::GeoVector2<float>(first.x, first.y) > NovelRT::Maths::GeoVector2<float>(other.x, other.y);
}

inline bool GeoVector2F_greaterThanOrEqualTo(const GeoVector2_t& first, const GeoVector2_t& other) {
  return NovelRT::Maths::GeoVector2<float>(first.x, first.y) >= NovelRT::Maths::GeoVector2<float>(other.x, other.y);
}

inline GeoVector2_t GeoVector2F_addVector(GeoVector2_t& first, const GeoVector2_t& other) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(first.x,first.y) + NovelRT::Maths::GeoVector2<float>(other.x, other.y);
  first.x = geo.getX();
  first.y = geo.getY();
  return first;
}

inline GeoVector2_t GeoVector2F_subtractVector(GeoVector2_t& first, const GeoVector2_t& other) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(first.x, first.y) - NovelRT::Maths::GeoVector2<float>(other.x, other.y);
  first.x = geo.getX();
  first.y = geo.getY();
  return first;
}

inline GeoVector2_t GeoVector2F_multiplyVector(GeoVector2_t& first, const GeoVector2_t& other) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(first.x, first.y) * NovelRT::Maths::GeoVector2<float>(other.x, other.y);
  first.x = geo.getX();
  first.y = geo.getY();
  return first;
}

inline GeoVector2_t GeoVector2F_divideVector(GeoVector2_t& first, const GeoVector2_t& other) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(first.x, first.y) / NovelRT::Maths::GeoVector2<float>(other.x, other.y);
  first.x = geo.getX();
  first.y = geo.getY();
  return first;
}

inline GeoVector2_t GeoVector2F_addFloat(GeoVector2_t& vector, float value) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(vector.x, vector.y) + value;
  vector.x = geo.getX();
  vector.y = geo.getY();
  return vector;
}

inline GeoVector2_t GeoVector2F_subtractFloat(GeoVector2_t& vector, float value) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(vector.x, vector.y) - value;
  vector.x = geo.getX();
  vector.y = geo.getY();
  return vector;
}

inline GeoVector2_t GeoVector2F_multiplyFloat(GeoVector2_t& vector, float value) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(vector.x, vector.y) * value;
  vector.x = geo.getX();
  vector.y = geo.getY();
  return vector;
}

GeoVector2_t GeoVector2F_divideFloat(GeoVector2_t& vector, float value) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(vector.x, vector.y) / value;
  vector.x = geo.getX();
  vector.y = geo.getY();
  return vector;
}

inline GeoVector2_t GeoVector2F_addIntoVector(GeoVector2_t& first, const GeoVector2_t& other) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(first.x, first.y);
  geo += NovelRT::Maths::GeoVector2<float>(other.x, other.y);
  first.x = geo.getX();
  first.y = geo.getY();
  return first;
}

inline GeoVector2_t GeoVector2F_subtractFromVector(GeoVector2_t& first, const GeoVector2_t& other) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(first.x, first.y);
  geo -= NovelRT::Maths::GeoVector2<float>(other.x, other.y);
  first.x = geo.getX();
  first.y = geo.getY();
  return first;
}

inline GeoVector2_t GeoVector2F_multiplyIntoVector(GeoVector2_t& first, const GeoVector2_t& other) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(first.x, first.y);
  geo *= NovelRT::Maths::GeoVector2<float>(other.x, other.y);
  first.x = geo.getX();
  first.y = geo.getY();
  return first;
}

GeoVector2_t GeoVector2F_divideIntoVector(GeoVector2_t& first, const GeoVector2_t& other) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(first.x, first.y);
  geo /= NovelRT::Maths::GeoVector2<float>(other.x, other.y);
  first.x = geo.getX();
  first.y = geo.getY();
  return first;
}

inline GeoVector2_t GeoVector2F_addFloatIntoVector(GeoVector2_t& vector, float value) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(vector.x, vector.y);
  geo += value;
  vector.x = geo.getX();
  vector.y = geo.getY();
  return vector;
}

inline GeoVector2_t GeoVector2F_subFloatFromVector(GeoVector2_t& vector, float value) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(vector.x, vector.y);
  geo -= value;
  vector.x = geo.getX();
  vector.y = geo.getY();
  return vector;
}

inline GeoVector2_t GeoVector2F_multiplyFloatIntoVector(GeoVector2_t& vector, float value) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(vector.x, vector.y);
  geo *= value;
  vector.x = geo.getX();
  vector.y = geo.getY();
  return vector;
}

inline GeoVector2_t GeoVector2F_divideFloatIntoVector(GeoVector2_t& vector, float value) {
  NovelRT::Maths::GeoVector2 geo = NovelRT::Maths::GeoVector2<float>(vector.x, vector.y);
  geo /= value;
  vector.x = geo.getX();
  vector.y = geo.getY();
  return vector;
}

inline GeoVector2_t GeoVector2F_multiplyFlip(float lhs, GeoVector2F& rhs) {
  return GeoVector2F_multiplyFloat(rhs, lhs);
}

#ifdef __cplusplus
}
#endif

#endif //NOVELRT_MATHS_GEOVECTOR2F_H