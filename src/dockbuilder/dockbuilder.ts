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

    DockWindow(window_name: string, node_id: number): void {
        Mod.export.DockBuilder_DockWindow(window_name, node_id);
    },

    AddNode(node_id: number = 0, flags: number = 0): number {
        return Mod.export.DockBuilder_AddNode(node_id, flags);
    },

    RemoveNode(node_id: number): void {
        Mod.export.DockBuilder_RemoveNode(node_id);
    },

    RemoveNodeChildNodes(node_id: number): void {
        Mod.export.DockBuilder_RemoveNodeChildNodes(node_id);
    },

    SetNodePos(node_id: number, x: number, y: number): void {
        Mod.export.DockBuilder_SetNodePos(node_id, x, y);
    },

    SetNodeSize(node_id: number, w: number, h: number): void {
        Mod.export.DockBuilder_SetNodeSize(node_id, w, h);
    },

    SplitNode(
        node_id: number,
        split_dir: number,
        size_ratio: number,
    ): { atDir: number; atOppositeDir: number } {
        return Mod.export.DockBuilder_SplitNode(node_id, split_dir, size_ratio);
    },

    Finish(node_id: number): void {
        Mod.export.DockBuilder_Finish(node_id);
    },
};
