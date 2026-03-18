// @ts-nocheck
import { Mod } from "./core.js";

export const ImGuizmo = {
    OPERATION: {
        TRANSLATE_X: 1 << 0,
        TRANSLATE_Y: 1 << 1,
        TRANSLATE_Z: 1 << 2,
        ROTATE_X: 1 << 3,
        ROTATE_Y: 1 << 4,
        ROTATE_Z: 1 << 5,
        ROTATE_SCREEN: 1 << 6,
        SCALE_X: 1 << 7,
        SCALE_Y: 1 << 8,
        SCALE_Z: 1 << 9,
        BOUNDS: 1 << 10,
        SCALE_XU: 1 << 11,
        SCALE_YU: 1 << 12,
        SCALE_ZU: 1 << 13,
        TRANSLATE: (1 << 0) | (1 << 1) | (1 << 2),
        ROTATE: (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6),
        SCALE: (1 << 7) | (1 << 8) | (1 << 9),
        SCALEU: (1 << 11) | (1 << 12) | (1 << 13),
        UNIVERSAL: (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 11) | (1 << 12) | (1 << 13),
    },

    MODE: {
        LOCAL: 0,
        WORLD: 1,
    },

    BeginFrame(): void {
        Mod.export.ImGuizmo_BeginFrame();
    },

    SetDrawlist(): void {
        Mod.export.ImGuizmo_SetDrawlist();
    },

    SetRect(x: number, y: number, width: number, height: number): void {
        Mod.export.ImGuizmo_SetRect(x, y, width, height);
    },

    Enable(enable: boolean): void {
        Mod.export.ImGuizmo_Enable(enable);
    },

    SetGizmoSizeClipSpace(value: number): void {
        Mod.export.ImGuizmo_SetGizmoSizeClipSpace(value);
    },

    IsOver(): boolean {
        return Mod.export.ImGuizmo_IsOver();
    },

    IsUsing(): boolean {
        return Mod.export.ImGuizmo_IsUsing();
    },

    SetOrthographic(isOrthographic: boolean): void {
        Mod.export.ImGuizmo_SetOrthographic(isOrthographic);
    },

    Manipulate(
        view: number[],
        projection: number[],
        operation: number,
        mode: number,
        matrix: number[],
        snap?: number[] | null,
    ): boolean {
        return Mod.export.ImGuizmo_Manipulate(
            view,
            projection,
            operation,
            mode,
            matrix,
            snap ?? null,
        );
    },

    DecomposeMatrixToComponents(matrix: number[]): {
        translation: number[];
        rotation: number[];
        scale: number[];
    } {
        return Mod.export.ImGuizmo_DecomposeMatrixToComponents(matrix);
    },

    RecomposeMatrixFromComponents(
        translation: number[],
        rotation: number[],
        scale: number[],
    ): number[] {
        return Mod.export.ImGuizmo_RecomposeMatrixFromComponents(
            translation,
            rotation,
            scale,
        );
    },
};
