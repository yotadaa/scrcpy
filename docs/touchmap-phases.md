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
- TODO: import/export JSON, per-game profiles.

## Phase 3 – Advanced control types
- TODO: D-pad, swipe, aim/pan/shoot, multi-key sequences.

## Phase 4 – Drag-and-drop sidebar palette
- TODO: right-side preset chip rail + ghost preview.

## Phase 5 – UX polish
- TODO: handles, grid snapping, undo.
