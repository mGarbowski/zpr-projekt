//
// Created by michluszcz on 23.11.24.
//

#include "RoadConverter.h"

void RoadConverter::addRoad(b2WorldId world_id, const Road& road, float x, float y) {
  b2BodyId ground_id;
  b2BodyDef body_def = b2DefaultBodyDef();
  ground_id = b2CreateBody(world_id, &body_def);
  b2ChainDef chain_def = b2DefaultChainDef();
  b2Vec2 points[road.points_.size()];
  for (int i = 0; i < road.points_.size(); i++) {
      points[i] = {road.points_[i].first, road.points_[i].second};
  }
  chain_def.points = points;
  chain_def.count = road.points_.size();
  chain_def.isLoop = true;
  b2CreateChain( ground_id, &chain_def );
}
