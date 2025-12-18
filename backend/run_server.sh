#!/bin/bash

# executable name
TARGET=server

# compile required cpp files
g++ -std=c++17 -Wall \
    -Iinclude \
    main.cpp \
    src/addNode.cpp \
    src/addEdge.cpp \
    src/deleteNode.cpp \
    src/deleteEdge.cpp \
    src/workflow/edgeSerializer.cpp \
    src/workflow/nodeSerializer.cpp \
    src/utils/str_to_int.cpp \
    deliver/node_deliver.cpp \
    deliver/edge_deliver.cpp \
    include/database_instance.cpp \
    deliver/query_deliver.cpp \
    src/getChildren.cpp \
    src/getParents.cpp \
    src/flags/detect_cycle.cpp \
    src/flags/disconnected_flow.cpp \
    src/flags/negative_cycle.cpp \
    src/flags/negative_weight_edge.cpp \
    src/flags/orphan_node.cpp \
    src/utils/working_flow.cpp \
    deliver/flag_deliver.cpp \
    debug.cpp \
    deliver/clear_graph.cpp \
    -o $TARGET

# check compilation status
if [ $? -ne 0 ]; then
    echo "❌ Compilation failed"
    exit 1
fi

echo "✅ Compilation successful"
echo "🚀 Running server..."
./$TARGET
