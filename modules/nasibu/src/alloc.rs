use crate::bindings::{size_t, vfree2, vmalloc};
use core::alloc::{GlobalAlloc, Layout};
use core::ptr;

struct KernAlloc;

#[global_allocator]
static GLOBAL: KernAlloc = KernAlloc;

unsafe impl GlobalAlloc for KernAlloc {
    unsafe fn alloc(&self, layout: Layout) -> *mut u8 {
        if let Ok(checked_size) = layout.size().try_into() {
            vmalloc(checked_size).cast()
        } else {
            ptr::null_mut()
        }
    }

    unsafe fn dealloc(&self, ptr: *mut u8, layout: Layout) {
        vfree2(ptr.cast(), layout.size() as size_t)
    }
}
