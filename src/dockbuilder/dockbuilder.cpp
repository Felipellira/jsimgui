#include <util.hpp>

#include <imgui.h>
#include <imgui_internal.h>

// clang-format off
static auto const DOCKBUILDER = bindings([]() {

bind_fn("DockBuilder_DockWindow", [](std::string window_name, unsigned int node_id) {
    ImGui::DockBuilderDockWindow(window_name.c_str(), node_id);
});

bind_fn("DockBuilder_AddNode", [](unsigned int node_id, int flags) {
    return ImGui::DockBuilderAddNode(node_id, static_cast<ImGuiDockNodeFlags>(flags));
});

bind_fn("DockBuilder_RemoveNode", [](unsigned int node_id) {
    ImGui::DockBuilderRemoveNode(node_id);
});

bind_fn("DockBuilder_RemoveNodeChildNodes", [](unsigned int node_id) {
    ImGui::DockBuilderRemoveNodeChildNodes(node_id);
});

bind_fn("DockBuilder_SetNodeSize", [](unsigned int node_id, float w, float h) {
    // Access the node directly to avoid ImVec2 ABI issues in extern C
    ImGuiDockNode* node = ImGui::DockBuilderGetNode(node_id);
    if (node) {
        node->SizeRef = ImVec2(w, h);
    }
});

bind_fn("DockBuilder_SplitNode", [](
    unsigned int node_id,
    int split_dir,
    float size_ratio_for_node_at_dir
) {
    ImGuiID out_id_at_dir = 0;
    ImGuiID out_id_at_opposite_dir = 0;

    ImGui::DockBuilderSplitNode(
        node_id,
        static_cast<ImGuiDir>(split_dir),
        size_ratio_for_node_at_dir,
        &out_id_at_dir,
        &out_id_at_opposite_dir
    );

    auto result = js_val::object();
    result.set("atDir", out_id_at_dir);
    result.set("atOppositeDir", out_id_at_opposite_dir);
    return result;
});

bind_fn("DockBuilder_Finish", [](unsigned int node_id) {
    ImGui::DockBuilderFinish(node_id);
});

});
// clang-format on
