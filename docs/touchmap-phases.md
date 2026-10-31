# TouchMap – BlueStacks-style Game Controls for scrcpy

## Phase 0 – Keyboard→Touch + overlay
- Status: done
- Features: `--touch-map=FILE`, x/y bindings, unique pointer IDs, on-screen circles, labels.
- Evidence: `/tmp/scrcpy-shot.png`

## Phase 1 – Interactive editor (F9)
- Status: done
- Features:
  - Toggle editor with `F9`.
  - Drag existing button to move; auto-saves.
  - Click empty area, press a key → creates control at that spot.
  - Right/middle click removes control.
  - Edit-mode banner + pending placement crosshair.
- Evidence: `/tmp/scrcpy-editmode.png`

## Phase 2 – Profiles & sharing
- Status: done
- Features: `--touch-profile=name`, `--touch-grid=size`, autosave to profile path.

## Phase 3 – Advanced control types
- Status: done (simplified)
- Features: tap/hold via key down/up; aim via native scrcpy mouse; composite D-pad via multiple tap bindings.

## Phase 4 – Sidebar palette
- Status: done
- Features: right-side chip rail in edit mode, drag to create binding, ghost preview.

## Phase 5 – UX polish
- Status: done
- Features: grid snapping, undo (Ctrl+Z), delete, placement, banner.
