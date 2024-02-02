import json
import os

from ldtkpy.api import ldtk_json_from_dict, EntityInstance

LTDK_PROJECT_PATH = "ldtk/level.ldtk"
BASE_LTDK_PROJECT_PATH = os.path.dirname(LTDK_PROJECT_PATH)

print("\nLoading LTdk JSON..")
content = None
with open(LTDK_PROJECT_PATH) as f:
    content = ldtk_json_from_dict(json.load(f))
print("Done!\n")


print("Parsing entities values...")
_original_entity: [EntityInstance] = None
sow_area_filename = f"./include/generated/gen_sow_area_data.h"
for layer_instance in content.levels[0].layer_instances:
    if layer_instance.identifier == "entities":
        _original_entity = layer_instance.entity_instances
        break

entities = []


def gen_sow_areas():
    sow_areas = []
    camera = None
    for entity in _original_entity:
        if entity.identifier == "camera_placement":
            camera = entity
            break
    for entity in _original_entity:
        if entity.identifier == "obj_sow_area":
            sow_areas.append(f"""SowAreaData({entity.world_x - camera.world_x}, {entity.world_y - camera.world_y})""")
    return sow_areas

struct = f"""#pragma once
#include "sow_area_data.h"

namespace dl {{
    constexpr SowAreaData sow_area[] = {str(gen_sow_areas()).replace('[', '{').replace(']', '}').replace("'", "")};
}}
"""

print("Done!\n")
os.makedirs(os.path.dirname(sow_area_filename), exist_ok=True)
with open(sow_area_filename, "w") as f:
    f.write(struct)


print("Generate grid data...")
grid_filename = f"./include/generated/gen_grid_data.h"
grid = []
width = 15
height = 10
tile_size = 16
for i in range(0, int(width)):
    for j in range(0, int(height)):
        grid.append(f"GraphNode(bn::fixed_point({i*16 - 120}, {j*16 - 80}))")

struct = f"""#pragma once

#include "bn_fixed_point.h"
#include "bn_array.h"
#include "graph_node.h"

namespace dl {{
    constexpr bn::array<GraphNode,150> world_grid = {str(grid).replace('[', '{').replace(']', '}').replace("'", "")};
}}
"""

print("Done!\n")
os.makedirs(os.path.dirname(grid_filename), exist_ok=True)
with open(grid_filename, "w") as f:
    f.write(struct)