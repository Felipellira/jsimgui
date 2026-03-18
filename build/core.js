export const Mod = {
    // biome-ignore lint/suspicious/noExplicitAny: _
    export: null,
    async init(enableFreeType, extensions, loaderPath) {
        // biome-ignore lint/suspicious/noExplicitAny: _
        let MainExport;
        console.log("[jsimgui] init called", { enableFreeType, extensions, loaderPath });
        try {
            if (loaderPath) {
                MainExport = await import(loaderPath);
            }
            else if (enableFreeType) {
                MainExport = extensions
                    ? // @ts-expect-error
                        await import("./wasm/loader-freetype-extensions.em.js")
                    : // @ts-expect-error
                        await import("./wasm/loader-freetype.em.js");
            }
            else {
                MainExport = extensions
                    ? // @ts-expect-error
                        await import("./wasm/loader-extensions.em.js")
                    : // @ts-expect-error
                        await import("./wasm/loader.em.js");
            }
            console.log("[jsimgui] import done, MainExport:", typeof MainExport);
            console.log("[jsimgui] MainExport keys:", MainExport ? Object.keys(MainExport) : "null");
            console.log("[jsimgui] MainExport.default:", typeof MainExport?.default);
            Mod.export = await MainExport.default();
            console.log("[jsimgui] Mod.export:", typeof Mod.export);
            console.log("[jsimgui] Mod.export.FS:", typeof Mod.export?.FS);
        }
        catch (e) {
            console.error("[jsimgui] init FAILED:", e);
            throw e;
        }
    },
};
/**
 * Base class for value structs (passed by value, no native pointer).
 */
export class ValueStruct {
}
/**
 * Base class for reference structs (carry native pointer/reference).
 * These structs manage native memory and require explicit cleanup.
 */
export class ReferenceStruct {
    /**
     * The native pointer to the struct.
     */
    // biome-ignore lint/suspicious/noExplicitAny: _
    ptr = null;
    /**
     * Construct a new JavaScript class instance and allocate native memory.
     */
    // biome-ignore lint/suspicious/noExplicitAny: _
    static New() {
        // biome-ignore lint/complexity/noThisInStatic: ...
        const obj = new this();
        // biome-ignore lint/complexity/noThisInStatic: ...
        obj.ptr = new Mod.export[this.name]();
        return obj;
    }
    /**
     * Create a JavaScript class instance from a native pointer.
     */
    // biome-ignore lint/suspicious/noExplicitAny: _
    static From(ptr) {
        // biome-ignore lint/complexity/noThisInStatic: ...
        const obj = new this();
        obj.ptr = ptr;
        return obj;
    }
    /**
     * Free the struct's native allocated memory.
     */
    Drop() {
        this.ptr?.delete();
    }
}
