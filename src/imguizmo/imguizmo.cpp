#include <util.hpp>

#include <imgui.h>
#include <ImGuizmo.h>
#include <cstdio>

// clang-format off
static auto const IMGUIZMO = bindings([]() {

bind_fn("ImGuizmo_BeginFrame", []() {
    ImGuizmo::BeginFrame();
});

bind_fn("ImGuizmo_SetDrawlist", []() {
    printf("[ImGuizmo C++] SetDrawlist\n");
    ImGuizmo::SetDrawlist();
    printf("[ImGuizmo C++] SetDrawlist done\n");
});

bind_fn("ImGuizmo_SetRect", [](float x, float y, float width, float height) {
    printf("[ImGuizmo C++] SetRect(%f, %f, %f, %f)\n", x, y, width, height);
    ImGuizmo::SetRect(x, y, width, height);
    printf("[ImGuizmo C++] SetRect done\n");
});

bind_fn("ImGuizmo_Enable", [](bool enable) {
    printf("[ImGuizmo C++] Enable(%d)\n", enable);
    ImGuizmo::Enable(enable);
    printf("[ImGuizmo C++] Enable done\n");
});

bind_fn("ImGuizmo_SetGizmoSizeClipSpace", [](float value) {
    printf("[ImGuizmo C++] SetGizmoSizeClipSpace(%f)\n", value);
    ImGuizmo::SetGizmoSizeClipSpace(value);
    printf("[ImGuizmo C++] SetGizmoSizeClipSpace done\n");
});

bind_fn("ImGuizmo_IsOver", []() {
    return ImGuizmo::IsOver();
});

bind_fn("ImGuizmo_IsUsing", []() {
    return ImGuizmo::IsUsing();
});

bind_fn("ImGuizmo_SetOrthographic", [](bool isOrthographic) {
    ImGuizmo::SetOrthographic(isOrthographic);
});

bind_fn("ImGuizmo_Manipulate", [](
    js_val view,
    js_val projection,
    int operation,
    int mode,
    js_val matrix,
    js_val snap
) {
    printf("[ImGuizmo C++] Manipulate op=%d mode=%d\n", operation, mode);
    auto param_view = get_array_param<float, 16>(view);
    auto param_projection = get_array_param<float, 16>(projection);
    auto param_matrix = get_array_param<float, 16>(matrix);
    auto param_snap = get_array_param<float, 3>(snap);
    printf("[ImGuizmo C++] arrays parsed: view=%p proj=%p mat=%p snap=%p\n",
        (void*)param_view.ptr, (void*)param_projection.ptr, (void*)param_matrix.ptr, (void*)param_snap.ptr);

    bool modified = ImGuizmo::Manipulate(
        param_view.ptr,
        param_projection.ptr,
        static_cast<ImGuizmo::OPERATION>(operation),
        static_cast<ImGuizmo::MODE>(mode),
        param_matrix.ptr,
        nullptr, // deltaMatrix
        param_snap.ptr,
        nullptr, // localBounds
        nullptr  // boundsSnap
    );

    if (modified) {
        write_back_array_param(param_matrix, matrix);
    }

    return modified;
});

bind_fn("ImGuizmo_DecomposeMatrixToComponents", [](js_val matrix) {
    auto param_matrix = get_array_param<float, 16>(matrix);
    float translation[3], rotation[3], scale[3];

    ImGuizmo::DecomposeMatrixToComponents(
        param_matrix.ptr,
        translation,
        rotation,
        scale
    );

    auto result = js_val::object();
    auto t = js_val::array();
    auto r = js_val::array();
    auto s = js_val::array();
    for (int i = 0; i < 3; i++) {
        t.set(i, translation[i]);
        r.set(i, rotation[i]);
        s.set(i, scale[i]);
    }
    result.set("translation", t);
    result.set("rotation", r);
    result.set("scale", s);
    return result;
});

bind_fn("ImGuizmo_RecomposeMatrixFromComponents", [](
    js_val translation,
    js_val rotation,
    js_val scale
) {
    auto param_t = get_array_param<float, 3>(translation);
    auto param_r = get_array_param<float, 3>(rotation);
    auto param_s = get_array_param<float, 3>(scale);
    float matrix[16];

    ImGuizmo::RecomposeMatrixFromComponents(
        param_t.ptr,
        param_r.ptr,
        param_s.ptr,
        matrix
    );

    auto result = js_val::array();
    for (int i = 0; i < 16; i++) {
        result.set(i, matrix[i]);
    }
    return result;
});

});
// clang-format on
