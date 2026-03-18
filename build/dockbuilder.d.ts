export declare const DockBuilder: {
    Dir: {
        None: number;
        Left: number;
        Right: number;
        Up: number;
        Down: number;
    };
    DockWindow(window_name: string, node_id: number): void;
    AddNode(node_id?: number, flags?: number): number;
    RemoveNode(node_id: number): void;
    RemoveNodeChildNodes(node_id: number): void;
    SetNodePos(node_id: number, x: number, y: number): void;
    SetNodeSize(node_id: number, w: number, h: number): void;
    SplitNode(node_id: number, split_dir: number, size_ratio: number): {
        atDir: number;
        atOppositeDir: number;
    };
    Finish(node_id: number): void;
};
