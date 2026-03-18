// @ts-nocheck
import { Mod } from "./core.js";
export const DockBuilder = {
    Dir: {
        None: -1,
        Left: 0,
        Right: 1,
        Up: 2,
        Down: 3,
    },
    DockWindow(window_name, node_id) {
        Mod.export.DockBuilder_DockWindow(window_name, node_id);
    },
    AddNode(node_id = 0, flags = 0) {
        Mod.export.DockBuilder_AddNode(node_id, flags);
    },
    RemoveNode(node_id) {
        Mod.export.DockBuilder_RemoveNode(node_id);
    },
    RemoveNodeChildNodes(node_id) {
        Mod.export.DockBuilder_RemoveNodeChildNodes(node_id);
    },
    SetNodePos(node_id, x, y) {
        Mod.export.DockBuilder_SetNodePos(node_id, x, y);
    },
    SetNodeSize(node_id, w, h) {
        Mod.export.DockBuilder_SetNodeSize(node_id, w, h);
    },
    SplitNode(node_id, split_dir, size_ratio) {
        return Mod.export.DockBuilder_SplitNode(node_id, split_dir, size_ratio);
    },
    Finish(node_id) {
        Mod.export.DockBuilder_Finish(node_id);
    },
};
