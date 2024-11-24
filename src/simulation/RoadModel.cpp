//
// Created by michluszcz on 23.11.24.
//

#include "RoadModel.h"

RoadModel RoadModel::create(b2WorldId world_id, const Road& road, Position position) {
  int road_length = road.points_.size();
  b2BodyId ground_id;
  b2BodyDef body_def = b2DefaultBodyDef();
  ground_id = b2CreateBody(world_id, &body_def);
  b2ChainDef chain_def = b2DefaultChainDef();
  b2Vec2 points[road_length];
  for (int i = 0; i < road_length; i++) {
      points[i] = {road.points_[i].first + position.x, road.points_[i].second + position.y};
  }
  chain_def.points = points;
  chain_def.count = road_length;
  chain_def.isLoop = true;
  b2CreateChain( ground_id, &chain_def );
  Position ending {road.points_[road_length-1].first, road.points_[road_length-1].second};
  return RoadModel(ground_id, position, ending);
}

b2BodyId RoadModel::bodyId() const {
  return body_id_;
}
Position RoadModel::getBeginning() const {
  return beginning_;
}

Position RoadModel::getEnd() const {
  return end_;
}
