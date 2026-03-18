#include <util.hpp>

#include <imgui.h>
#include <imgui_internal.h>
#include <cstdio>

// clang-format off
static auto const DOCKBUILDER = bindings([]() {

bind_fn("DockBuilder_DockWindow", [](std::string window_name, unsigned int node_id) {
    printf("[DockBuilder C++] DockWindow('%s', %u)\n", window_name.c_str(), node_id);
    ImGui::DockBuilderDockWindow(window_name.c_str(), node_id);
    printf("[DockBuilder C++] DockWindow done\n");
});

bind_fn("DockBuilder_AddNode", [](unsigned int node_id, int flags) {
    printf("[DockBuilder C++] AddNode(%u, %d)\n", node_id, flags);
    ImGui::DockBuilderAddNode(node_id, static_cast<ImGuiDockNodeFlags>(flags));
    printf("[DockBuilder C++] AddNode done\n");
});

bind_fn("DockBuilder_RemoveNode", [](unsigned int node_id) {
    printf("[DockBuilder C++] RemoveNode(%u)\n", node_id);
    ImGui::DockBuilderRemoveNode(node_id);
    printf("[DockBuilder C++] RemoveNode done\n");
});

bind_fn("DockBuilder_RemoveNodeChildNodes", [](unsigned int node_id) {
    printf("[DockBuilder C++] RemoveNodeChildNodes(%u)\n", node_id);
    ImGui::DockBuilderRemoveNodeChildNodes(node_id);
    printf("[DockBuilder C++] RemoveNodeChildNodes done\n");
});

bind_fn("DockBuilder_SetNodeSize", [](unsigned int node_id, float w, float h) {
    printf("[DockBuilder C++] SetNodeSize(%u, %f, %f)\n", node_id, w, h);
    ImGuiDockNode* node = ImGui::DockBuilderGetNode(node_id);
    printf("[DockBuilder C++] GetNode returned %p\n", (void*)node);
    if (node) {
        node->SizeRef = ImVec2(w, h);
        printf("[DockBuilder C++] SizeRef set\n");
    } else {
        printf("[DockBuilder C++] WARNING: node is null!\n");
    }
});

bind_fn("DockBuilder_SplitNode", [](
    unsigned int node_id,
    int split_dir,
    float size_ratio_for_node_at_dir
) {
    printf("[DockBuilder C++] SplitNode(%u, dir=%d, ratio=%f)\n", node_id, split_dir, size_ratio_for_node_at_dir);
    ImGuiID out_id_at_dir = 0;
    ImGuiID out_id_at_opposite_dir = 0;

    ImGui::DockBuilderSplitNode(
        node_id,
        static_cast<ImGuiDir>(split_dir),
        size_ratio_for_node_at_dir,
        &out_id_at_dir,
        &out_id_at_opposite_dir
    );

    printf("[DockBuilder C++] SplitNode => atDir=%u, atOpposite=%u\n", out_id_at_dir, out_id_at_opposite_dir);

    auto result = js_val::object();
    result.set("atDir", out_id_at_dir);
    result.set("atOppositeDir", out_id_at_opposite_dir);
    return result;
});

bind_fn("DockBuilder_Finish", [](unsigned int node_id) {
    printf("[DockBuilder C++] Finish(%u)\n", node_id);
    ImGui::DockBuilderFinish(node_id);
    printf("[DockBuilder C++] Finish done\n");
});

});
// clang-format on
