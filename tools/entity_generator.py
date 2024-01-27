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
    for entity in _original_entity:
        if entity.identifier == "obj_sow_area":
            sow_areas.append(f"""SowAreaData({entity.world_x}, {entity.world_y})""")
    return sow_areas

struct = f"""#pragma once
#include "sow_area.h"

namespace dl {{
    constexpr SowAreaData sow_area[] = {str(gen_sow_areas()).replace('[', '{').replace(']', '}').replace("'", "")};
}}
"""

print("Done!\n")
os.makedirs(os.path.dirname(sow_area_filename), exist_ok=True)
with open(sow_area_filename, "w") as f:
    f.write(struct)