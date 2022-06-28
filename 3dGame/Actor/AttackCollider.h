#ifndef ATTACK_COLLIDER_H_
#define ATTACK_COLLIDER_H_

#include"Actor.h"
#include<memory>

class AttackCollider :public Actor 
{
public:
	//コンストラクタ
	AttackCollider(std::shared_ptr<IWorld> world, const BoundingSphere& collider,
		const std::string& tag, const std::string& name,
		const std::string& owner_tag = "",
		float lifespan = 1.0f, float delay = 0.0f);

	//更新
	virtual void update(float delta_time)override;
	//描画
	virtual void draw()const override;
	//衝突リアクション
	virtual void react(Actor& ohter)override;

private:
	//攻撃判定を出現させたアクターのタグ
	std::string owner_tag_;
	//寿命
	float lifespan_timer_;
	//衝突判定が行こうになるまでの遅延時間
	float delay_timer_;
};

#endif // !ATTACK_COLLIDER_H_

