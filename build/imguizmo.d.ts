export declare const ImGuizmo: {
    OPERATION: {
        TRANSLATE_X: number;
        TRANSLATE_Y: number;
        TRANSLATE_Z: number;
        ROTATE_X: number;
        ROTATE_Y: number;
        ROTATE_Z: number;
        ROTATE_SCREEN: number;
        SCALE_X: number;
        SCALE_Y: number;
        SCALE_Z: number;
        BOUNDS: number;
        SCALE_XU: number;
        SCALE_YU: number;
        SCALE_ZU: number;
        TRANSLATE: number;
        ROTATE: number;
        SCALE: number;
        SCALEU: number;
        UNIVERSAL: number;
    };
    MODE: {
        LOCAL: number;
        WORLD: number;
    };
    BeginFrame(): void;
    SetDrawlist(): void;
    SetRect(x: number, y: number, width: number, height: number): void;
    Enable(enable: boolean): void;
    SetGizmoSizeClipSpace(value: number): void;
    IsOver(): boolean;
    IsUsing(): boolean;
    SetOrthographic(isOrthographic: boolean): void;
    Manipulate(view: number[], projection: number[], operation: number, mode: number, matrix: number[], snap?: number[] | null): boolean;
    DecomposeMatrixToComponents(matrix: number[]): {
        translation: number[];
        rotation: number[];
        scale: number[];
    };
    RecomposeMatrixFromComponents(translation: number[], rotation: number[], scale: number[]): number[];
};
