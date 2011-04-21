<?php

/**
 * Implementation of hook_content_default_fields().
 */
function worx_blog_content_default_fields() {
  $fields = array();

  // Exported field: field_worx_blog_be_image
  $fields['blog-field_worx_blog_be_image'] = array(
    'field_name' => 'field_worx_blog_be_image',
    'type_name' => 'blog',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      '4' => array(
        'format' => 'worx_blog_be_scale_200w_linked',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'worx_blog_be_scale_200w_linked',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'worx_blog_be_scale_200w_imagelink',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => 'worx_blog/blog/images',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '1000x1000',
      'min_resolution' => '200x200',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Images',
      'weight' => '-3',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Images');

  return $fields;
}
