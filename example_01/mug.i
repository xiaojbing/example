[Mesh]
  file = mug.e
[]

[Variables]
  [dif]
    order = FIRST
    family = LAGRANGE
  []
[]

[Kernels]
  [diffusion]
    type = Diffusion
    variable = dif
  []
[]

[BCs]
  [bottom]
    type = DirichletBC
    boundary = bottom
    variable = dif
    value = 1
  []

  [top]
    type = DirichletBC
    boundary = top
    variable = dif
    value = 0
  []
[]

[Executioner]
  type = Steady
  solve_type = PJFNK
[]

[Outputs]
  execute_on = TIMESTEP_END
  file_base = mug_out
  exodus = true
[]
