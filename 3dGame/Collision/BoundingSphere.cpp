#include "BoundingSphere.h"

// コンストラクタ
BoundingSphere::BoundingSphere(float radius, const GSvector3& center) :
    radius_{ radius }, center_{ center } {
}

// 平行移動
BoundingSphere BoundingSphere::translate(const GSvector3& position) const {
    return BoundingSphere{ radius_, center_ + position };
}

// 座標変換
BoundingSphere BoundingSphere::transform(const GSmatrix4& matrix) const {
    return BoundingSphere{ radius_ * matrix.getScale().y, matrix.transform(center_) };
}


// 交差しているか？
bool BoundingSphere::intersects(const BoundingSphere& other) const {
    return gsCollisionSphereAndSphere(
        &center_, radius_, &other.center_, other.radius_) == GS_TRUE;
}

// デバッグ表示
void BoundingSphere::draw() const {
    glPushMatrix();
    glTranslatef(center_.x, center_.y, center_.z);
    glutWireSphere(radius_, 16, 16); // ワイヤーフレームの球体を描画
    glPopMatrix();
}

