#include <util.hpp>

#include <imgui.h>

// Use the C API from dcimgui_internal (already compiled into WASM)
extern "C" {
    void ImGui_DockBuilderDockWindow(const char* window_name, ImGuiID node_id);
    ImGuiID ImGui_DockBuilderAddNodeEx(ImGuiID node_id, ImGuiDockNodeFlags flags);
    void ImGui_DockBuilderRemoveNode(ImGuiID node_id);
    void ImGui_DockBuilderRemoveNodeChildNodes(ImGuiID node_id);
    void ImGui_DockBuilderSetNodePos(ImGuiID node_id, ImVec2 pos);
    void ImGui_DockBuilderSetNodeSize(ImGuiID node_id, ImVec2 size);
    ImGuiID ImGui_DockBuilderSplitNode(ImGuiID node_id, ImGuiDir split_dir, float size_ratio_for_node_at_dir, ImGuiID* out_id_at_dir, ImGuiID* out_id_at_opposite_dir);
    void ImGui_DockBuilderFinish(ImGuiID node_id);
}

// clang-format off
static auto const DOCKBUILDER = bindings([]() {

bind_fn("DockBuilder_DockWindow", [](std::string window_name, unsigned int node_id) {
    ImGui_DockBuilderDockWindow(window_name.c_str(), node_id);
});

bind_fn("DockBuilder_AddNode", [](unsigned int node_id, int flags) {
    return ImGui_DockBuilderAddNodeEx(node_id, static_cast<ImGuiDockNodeFlags>(flags));
});

bind_fn("DockBuilder_RemoveNode", [](unsigned int node_id) {
    ImGui_DockBuilderRemoveNode(node_id);
});

bind_fn("DockBuilder_RemoveNodeChildNodes", [](unsigned int node_id) {
    ImGui_DockBuilderRemoveNodeChildNodes(node_id);
});

bind_fn("DockBuilder_SetNodePos", [](unsigned int node_id, float x, float y) {
    ImGui_DockBuilderSetNodePos(node_id, ImVec2(x, y));
});

bind_fn("DockBuilder_SetNodeSize", [](unsigned int node_id, float w, float h) {
    ImGui_DockBuilderSetNodeSize(node_id, ImVec2(w, h));
});

bind_fn("DockBuilder_SplitNode", [](
    unsigned int node_id,
    int split_dir,
    float size_ratio_for_node_at_dir
) {
    ImGuiID out_id_at_dir = 0;
    ImGuiID out_id_at_opposite_dir = 0;

    ImGui_DockBuilderSplitNode(
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
    ImGui_DockBuilderFinish(node_id);
});

});
// clang-format on
