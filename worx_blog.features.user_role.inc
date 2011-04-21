<?php

/**
 * Implementation of hook_user_default_roles().
 */
function worx_blog_user_default_roles() {
  $roles = array();

  // Exported role: blog administrator
  $roles['blog administrator'] = array(
    'name' => 'blog administrator',
  );

  // Exported role: trusted blogger
  $roles['trusted blogger'] = array(
    'name' => 'trusted blogger',
  );

  // Exported role: untrusted blogger
  $roles['untrusted blogger'] = array(
    'name' => 'untrusted blogger',
  );

  return $roles;
}
